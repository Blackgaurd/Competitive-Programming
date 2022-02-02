// An Animal Contest 5 P1 - Bamboo Cookies

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
	e := 0
	for i := 0; i < n; i++ {
		e += su() % 2
	}
	fmt.Println(e/2 + (n-e)/2)
}
