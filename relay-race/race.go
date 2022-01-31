package main

import (
	"fmt"
	"time"
)

// simular corrida de revezamento
// 4 corredores
// o sedundo o terceiro e o quarto corredor nao podem correr ate receberem o bastao de seu atecessor
// utilizar o metodos sleep para simular o tempo utilizado

func run(runners chan int, runner int) {
	fmt.Printf("Runner %v start run\n", runner)
	time.Sleep(1 * time.Second)
	runner += 1
	runners <- runner
}

func main() {
	runners := make(chan int)
	go run(runners, 1)
	fmt.Printf("The pipe was passed\n")
	go run(runners, <-runners)
	fmt.Println("The pipe was passed\n")
	go run(runners, <-runners)
	fmt.Println("The pipe was passed\n")
	go run(runners, <-runners)
	fmt.Println("The race was ended\n")
}
