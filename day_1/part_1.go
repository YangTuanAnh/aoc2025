package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve() {
	in := bufio.NewScanner(os.Stdin)
	ans := 0
	curr := 50

	for in.Scan() {
		s := in.Text()
		if len(s) == 0 {
			continue
		}

		c := s[0]
		cnt := 0
		for i := 1; i < len(s); i++ {
			cnt = cnt*10 + int(s[i]-'0')
		}
		cnt %= 100

		if c == 'L' {
			curr -= cnt
		} else {
			curr += cnt
		}

		curr = (curr + 100) % 100
		if curr == 0 {
			ans++
		}
	}

	fmt.Println(ans)
}

func main() {
	f, err := os.Open("input.txt")
	if err != nil {
		panic(err)
	}
	defer f.Close()

	os.Stdin = f
	solve()
}
