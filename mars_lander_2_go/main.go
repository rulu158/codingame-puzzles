package main

import (
	"fmt"
	"math"
	"os"
)

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 type Surface struct {
	pointsX                                   []int
	pointsY                                   []int
	FlatHeight, MaxHeight, FlatXmin, FlatXmax int
}

func main() {
    // surfaceN: the number of points used to draw the surface of Mars.
    var surfaceN int
    fmt.Scan(&surfaceN)
    
	surface := &Surface{
		pointsX:    make([]int, surfaceN),
		pointsY:    make([]int, surfaceN),
		FlatHeight: 3000,
		MaxHeight:  0,
	}

    for i := 0; i < surfaceN; i++ {
        // landX: X coordinate of a surface point. (0 to 6999)
        // landY: Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        var landX, landY int
        fmt.Scan(&landX, &landY)

		surface.pointsX[i] = landX
		surface.pointsY[i] = landY

		if i > 0 && surface.pointsY[i] == surface.pointsY[i-1] {
			surface.FlatXmin = surface.pointsX[i-1]
			surface.FlatXmax = surface.pointsX[i]
			surface.FlatHeight = surface.pointsY[i]
		}

		if landY > surface.MaxHeight {
			surface.MaxHeight = landY
		}
    }

	fmt.Fprintf(os.Stderr, "flat area start: %v; flat area end: %v; flat area height: %v; surfaceN: %v\n", surface.FlatXmin, surface.FlatXmax, surface.FlatHeight, surfaceN)
	fmt.Fprintf(os.Stderr, "pointsX: %v\n", surface.pointsX)

    for {
        // hSpeed: the horizontal speed (in m/s), can be negative.
        // vSpeed: the vertical speed (in m/s), can be negative.
        // fuel: the quantity of remaining fuel in liters.
        // rotate: the rotation angle in degrees (-90 to 90).
        // power: the thrust power (0 to 4).
        var X, Y, hSpeed, vSpeed, fuel, rotate, power int
        fmt.Scan(&X, &Y, &hSpeed, &vSpeed, &fuel, &rotate, &power)
        
        
        // fmt.Fprintln(os.Stderr, "Debug messages...")
        
        // rotate power. rotate is the desired rotation angle. power is the desired thrust power.
		//fmt.Fprintln(os.Stderr, "y:", surface.pointsY[2500])
		if X >= surface.FlatXmin - 500 && X <= surface.FlatXmax + 500 {
			if vSpeed <= -39 && math.Abs(float64(hSpeed)) <= 20 {
				fmt.Println("0 4")
			} else if math.Abs(float64(hSpeed)) >= 15 && hSpeed > 0 {
				fmt.Println("25 4")
			} else if math.Abs(float64(hSpeed)) >= 15 && hSpeed < 0 {
				fmt.Println("-25 4")
			} else {
				fmt.Println("0 3")
			}
		} else if X < surface.FlatXmin && Y - surface.FlatHeight > 1500 {
			if math.Abs(float64(hSpeed)) >= 30 && hSpeed > 0 {
				if hSpeed >= 70 {
					fmt.Println("50 4")
				} else {
					fmt.Println("22 4")
				}
			} else {
				if hSpeed <= -70 {
					fmt.Println("-50 4")
				} else {
       				fmt.Println("-22 4")
				}
			}
		} else if X > surface.FlatXmax && Y - surface.FlatHeight > 1500 {
			if math.Abs(float64(hSpeed)) >= 30 && hSpeed < 0 {
				if hSpeed <= -50 {
					fmt.Println("-50 4")
				} else {
					fmt.Println("-22 4")
				}
			} else {
				if hSpeed >= 50 {
       				fmt.Println("50 4")
				} else {
					fmt.Println("22 4")
				}
			}
		} else if ((X < surface.FlatXmin && Y - surface.FlatHeight < 1500) || (X > surface.FlatXmax && Y - surface.FlatHeight < 1500)) && vSpeed < 2 {
			fmt.Println("0 4")
		} else if vSpeed <= -39 && math.Abs(float64(hSpeed)) <= 20 {
			fmt.Println("0 1")
		} else {
			fmt.Println("0 3")
		}
    }
}
