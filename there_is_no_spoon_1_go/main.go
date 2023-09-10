package main

import "fmt"
import "os"
import "bufio"

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
type Cell struct {
	x, y   int
	isNode bool
	right  *Cell
	bottom *Cell
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 1000000), 1000000)

	// width: the number of cells on the X axis
	var width int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &width)

	// height: the number of cells on the Y axis
	var height int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &height)

    grid := make([][]*Cell, height, height)
    nodes := make([]*Cell, 0, height*width)

	for y := 0; y < height; y++ {
		scanner.Scan()
		line := scanner.Text()

        grid[y] = make([]*Cell, width, width)

		for x := 0; x < width; x++ {
            cell := &Cell{
                x: x,
                y: y,
                isNode: line[x] != '.',
            }

            if cell.x > 0 {
                grid[y][x-1].right = cell
            }
            if cell.y > 0 {
                grid[y-1][x].bottom = cell
            }

            grid[y][x] = cell
            if cell.isNode {
                nodes = append(nodes, cell)
            }
		}
	}

    for _, node := range nodes {
        rightPos := "-1 -1"
        bottomPos := "-1 -1"

        for cell := node; cell.right != nil; {
            if cell.right.isNode {
                rightPos = fmt.Sprintf("%d %d", cell.right.x, cell.right.y)
                break
            }
            cell = cell.right
        }
        for cell := node; cell.bottom != nil; {
            if cell.bottom.isNode {
                bottomPos = fmt.Sprintf("%d %d", cell.bottom.x, cell.bottom.y)
                break
            }
            cell = cell.bottom
        }

        fmt.Println(node.x, node.y, rightPos, bottomPos)
    }
}

