// B. Squares and Cubes

package main

import (
	"fmt"
	"io/ioutil"
	"math"
	"os"
	"sort"
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

	const MM int = 1e9
	arr := make([]int, 0, 33000)
	for i := 1; i*i <= MM; i++ {
		arr = append(arr, i*i)
	}
	for i := 1; i*i*i <= MM; i++ {
		cube := i * i * i
		sqrt := int(math.Sqrt(float64(cube)))
		if sqrt*sqrt == cube {
			continue
		}
		arr = append(arr, cube)
	}
	sort.Slice(arr, func(i int, j int) bool { return arr[i] < arr[j] })

	t := su()
	for t > 0 {
		n := su()

		// upper bound
		lo, hi := 0, len(arr)-1
		for lo <= hi {
			mid := (lo + hi) / 2
			if arr[mid] > n {
				hi = mid - 1
			} else {
				lo = mid + 1
			}
		}
		fmt.Println(lo)
		t--
	}
}
