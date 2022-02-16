// VM7WC '16 #1 Bronze - A New Prime Factorization

package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

var _tk []string
var _inp int = 0

func su() int {
	r, _ := strconv.Atoi(_tk[_inp])
	_inp++
	return r
}
func main() {
	bytes, _ := ioutil.ReadAll(os.Stdin)
	_tk = strings.Fields(string(bytes))

	n := su()
	for n&1 == 0 {
		n >>= 1
		fmt.Println(2)
	}
	for i := 3; i*i <= n; i += 2 {
		for n%i == 0 {
			fmt.Println(i)
			n /= i
		}
	}
	if n != 1 {
		fmt.Println(n)
	}
}
