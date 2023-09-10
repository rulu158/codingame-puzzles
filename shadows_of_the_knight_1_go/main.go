package main

import "fmt"
import "strings"

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

func main() {
    // W: width of the building.
    // H: height of the building.
    var W, H int
    fmt.Scan(&W, &H)
    
    // N: maximum number of turns before game over.
    var N int
    fmt.Scan(&N)
    
    var X0, Y0 int
    fmt.Scan(&X0, &Y0)

	X := X0
	Y := Y0

	minX := 0
	maxX := W
	minY := 0
	maxY := H
    
    for {
        // bombDir: the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        var bombDir string
        fmt.Scan(&bombDir)
        
		if strings.Contains(bombDir, "U") {
			maxY = Y
			Y = (Y + minY) / 2
		} else if strings.Contains(bombDir, "D") {
			minY = Y
			Y = (maxY + Y) / 2
		}

		if strings.Contains(bombDir, "R") {
			minX = X
			X = (maxX + X) / 2
		} else if strings.Contains(bombDir, "L") {
			maxX = X
			X = (X + minX) / 2
		}
        
        // fmt.Fprintln(os.Stderr, "Debug messages...")
        
        // the location of the next window Batman should jump to.
        fmt.Printf("%d %d\n", X, Y)
    }
}
