// COCI '08 Contest 3 #1 Pet

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

	ind, mx := 0, 0
	for i := 1; i <= 5; i++ {
		sum := 0
		for j := 0; j < 4; j++ {
			sum += su()
		}
		if sum > mx {
			mx = sum
			ind = i
		}
	}
	fmt.Println(ind, mx)
}
