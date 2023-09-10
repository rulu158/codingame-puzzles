package main

import "fmt"

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

func main() {
    // lightX: the X position of the light of power
    // lightY: the Y position of the light of power
    // initialTx: Thor's starting X position
    // initialTy: Thor's starting Y position
    var lightX, lightY, initialTx, initialTy int
    fmt.Scan(&lightX, &lightY, &initialTx, &initialTy)
    
	Tx := initialTx
	Ty := initialTy

    for {
        // remainingTurns: The remaining amount of turns Thor can move. Do not remove this line.
        var remainingTurns int
        fmt.Scan(&remainingTurns)
        
		move := ""

        if Ty > lightY {
			Ty--
			move += "N"
		} else if Ty < lightY {
			Ty++
			move += "S"
		}

		if Tx < lightX {
			Tx++
			move += "E"
		} else if Tx > lightX {
			Tx--
			move += "W"
		}
        // fmt.Fprintln(os.Stderr, "Debug messages...")
        
        // A single line providing the move to be made: N NE E SE S SW W or NW
        fmt.Println(move)

		if remainingTurns == 0 {
			break
		}
    }
}
