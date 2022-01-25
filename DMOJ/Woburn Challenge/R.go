// WC '18 Contest 3 J3 - R

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
func main() {
	bytes, _ := ioutil.ReadAll(os.Stdin)
	_tk = strings.Fields(string(bytes))

	n := su()
	for i := 1; i < n; i++ {
		fmt.Print("#")
	}
	fmt.Println(".")
	for i := 0; i < n-2; i++ {
		fmt.Print("#")
		for j := 0; j < n-2; j++ {
			fmt.Print(".")
		}
		fmt.Println("#")
	}
	for i := 1; i < n; i++ {
		fmt.Print("#")
	}
	fmt.Println(".")
	for i := 1; i < n; i++ {
		fmt.Print("#")
		for j := 1; j < n; j++ {
			if i == j {
				fmt.Print("#")
			} else {
				fmt.Print(".")
			}
		}
		fmt.Println()
	}
}
