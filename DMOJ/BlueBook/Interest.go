// BlueBook - Interest

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
func sf() float64 {
	r, _ := strconv.ParseFloat(_tk[_iop], 64)
	_iop++
	return r
}
func main() {
	bytes, _ := ioutil.ReadAll(os.Stdin)
	_tk = strings.Fields(string(bytes))

	n := sf()
	m := sf()/100.0 + 1.0
	y := su()
	for i := 0; i <= y; i++ {
		fmt.Printf("%d %.2f\n", i, n)
		n *= m
	}
}
