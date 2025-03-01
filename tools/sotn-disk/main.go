package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"path"
	"strings"

	"github.com/xeeynamo/sotn-decomp/tools/sotn-disk/iso9660"
)

type imageAction func(iso9660.File) error

func performCueAction(cuePath string, action imageAction) error {
	// this parser is very basic and it's poorly resiliant

	content, err := ioutil.ReadFile(cuePath)
	if err != nil {
		return err
	}
	lines := strings.Split(string(content), "\n")

	var binFileName string
	var mode iso9660.TrackMode
	for _, line := range lines {
		tokens := strings.Split(strings.TrimSpace(line), " ")
		if len(tokens) < 2 {
			continue
		}

		switch tokens[0] {
		case "FILE":
			if len(tokens) < 3 {
				return fmt.Errorf("cue line '%s' invalid", line)
			}
			binFileName = strings.Split(tokens[1], "\"")[1]
		case "TRACK":
			if len(tokens) < 3 {
				return fmt.Errorf("cue line '%s' invalid", line)
			}
			switch tokens[2] {
			case "MODE1/2048":
				mode = iso9660.TrackMode1_2048
			case "MODE2/2352":
				mode = iso9660.TrackMode2_2352
			}
		}
	}

	baseDir, _ := path.Split(cuePath)
	binPath := path.Join(baseDir, binFileName)

	f, err := os.Open(binPath)
	if err != nil {
		return err
	}
	defer f.Close()

	image, err := iso9660.OpenImage(f, mode)
	if err != nil {
		return err
	}

	return action(image.RootDir())
}

func printHelp() {
	fmt.Printf("Usage: sotn-disc <command> <sotn.cue> [args]\n\n")
	fmt.Printf("Commands:\n")
	fmt.Printf("  list <sotn.cue>\n")
	fmt.Printf("    dump list of files and directories ordered by how they are stored on disc.\n")
	fmt.Printf("  extract <sotn.cue> <output path>\n")
	fmt.Printf("    extract all the files into the specified path\n")
	//fmt.Printf("  make <sotn.cue> <input path> <file list>\n")
	//fmt.Printf("    creates a PlayStation 1 image given an input path where the game files are located and their order")
}

func main() {
	if len(os.Args) < 3 {
		printHelp()
		return
	}

	var err error
	cmd := os.Args[1]
	cuePath := os.Args[2]
	switch cmd {
	case "list":
		err = performCueAction(cuePath, list)
	case "extract":
		if len(os.Args) < 4 {
			printHelp()
			return
		}
		outPath := os.Args[3]
		err = performCueAction(cuePath, func(f iso9660.File) error {
			return extract(f, outPath)
		})
	case "make":
		if len(os.Args) < 5 {
			printHelp()
			return
		}
		inPath := os.Args[3]
		fileListPath := os.Args[4]
		err = makeDisc(cuePath, inPath, fileListPath)
	}

	if err != nil {
		panic(err)
	}
}
