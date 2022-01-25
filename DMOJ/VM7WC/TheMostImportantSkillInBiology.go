// VM7WC '16 #6 Bronze - The Most Important Skill in Biology

package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

var _tk []string
var _iop int = 0

func su() int {
	r, _ := strconv.Atoi(_tk[_iop])
	_iop++
	return r
}

type point struct {
	x, y int
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
func main() {
	bytes, _ := ioutil.ReadAll(os.Stdin)
	_tk = strings.Fields(string(bytes))

	n := su()
	var arr []point
	for i := 0; i < n; i++ {
		arr = append(arr, point{su(), su()})
	}

	// shoelace theorem
	c1, c2 := arr[n-1].x*arr[0].y, arr[n-1].y*arr[0].x
	for i := 0; i < n-1; i++ {
		c1 += arr[i].x * arr[i+1].y
		c2 += arr[i].y * arr[i+1].x
	}
	area := (abs(c1-c2) + 1) / 2
	fmt.Println(area)
}
