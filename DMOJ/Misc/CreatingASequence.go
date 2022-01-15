// Creating A Sequence

package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

var tk []string
var ptr int = 0

func su() int {
	r, _ := strconv.Atoi(tk[ptr])
	ptr++
	return r
}
func main() {
	bytes, _ := ioutil.ReadAll(os.Stdin)
	tk = strings.Fields(string(bytes))

	n, k := su(), su()
	for i := 1; i < n; i++ {
		fmt.Print("0 ")
	}
	fmt.Println(k)
}
