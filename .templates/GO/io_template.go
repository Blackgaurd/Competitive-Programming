package main

import (
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

}
