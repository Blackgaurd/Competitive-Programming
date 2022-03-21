// SAC '22 Code Challenge 3 P2 - Unicycle License

package main

import (
	"fmt"
	"io/ioutil"
	"math"
	"os"
	"strconv"
	"strings"
)

var _tk []string
var _iop int = 0

func su() float64 {
	r, _ := strconv.ParseFloat(_tk[_iop], 64)
	_iop++
	return r
}
func main() {
	bytes, _ := ioutil.ReadAll(os.Stdin)
	_tk = strings.Fields(string(bytes))

	a, b, c := 12.0, -5.0, 1.0-su()
	ans := (-b + math.Sqrt(b*b-4*a*c)) / (2.0 * a)
	fmt.Println(ans)
}
