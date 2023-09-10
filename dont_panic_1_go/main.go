package main

import (
	"fmt"
	"os"
)

func main() {
	// nbFloors: number of floors
	// width: width of the area
	// nbRounds: maximum number of rounds
	// exitFloor: floor on which the exit is found
	// exitPos: position of the exit on its floor
	// nbTotalClones: number of generated clones
	// nbAdditionalElevators: ignore (always zero)
	// nbElevators: number of elevators
	var nbFloors, width, nbRounds, exitFloor, exitPos, nbTotalClones, nbAdditionalElevators, nbElevators int
	fmt.Scan(&nbFloors, &width, &nbRounds, &exitFloor, &exitPos, &nbTotalClones, &nbAdditionalElevators, &nbElevators)

	elevators := make(map[int]int)
	for i := 0; i < nbElevators; i++ {
		// elevatorFloor: floor on which this elevator is found
		// elevatorPos: position of the elevator on its floor
		var elevatorFloor, elevatorPos int
		fmt.Scan(&elevatorFloor, &elevatorPos)
		elevators[elevatorFloor] = elevatorPos
	}
	for {
		// cloneFloor: floor of the leading clone
		// clonePos: position of the leading clone on its floor
		// direction: direction of the leading clone: LEFT or RIGHT
		var cloneFloor, clonePos int
		var direction string
		fmt.Scan(&cloneFloor, &clonePos, &direction)

		fmt.Fprintln(os.Stderr, elevators[cloneFloor], exitFloor, exitPos, cloneFloor, clonePos, direction)

		var target int
		if cloneFloor == exitFloor {
			target = exitPos
		} else {
			target = elevators[cloneFloor]
		}

		if (direction == "RIGHT" && clonePos > target) ||
			(direction == "LEFT" && clonePos < target) {
			fmt.Println("BLOCK")
			continue
		}

		// fmt.Fprintln(os.Stderr, "Debug messages...")
		fmt.Println("WAIT") // action: WAIT or BLOCK
	}
}

