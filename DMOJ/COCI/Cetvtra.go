// COCI '07 Contest 1 #1 Cetvrta

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
	a, b := su(), su()
	a ^= su()
	b ^= su()
	a ^= su()
	b ^= su()
	fmt.Println(a, b)
}
