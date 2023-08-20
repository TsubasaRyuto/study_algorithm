package main
import "fmt"
func main(){
    array := []int{ 10, 8, 52, 17, 3, 31 }

    for i := 1; i < len(array) - 1; i++ {
        for j := len(array) - 1; j >= i; j-- {
            if (array[j - 1] > array[j]) {
                w := array[j]
                array[j] = array[j - 1]
                array[j - 1] = w
            }

            for _, value := range array {
                fmt.Printf(" - %d", value)
            }
            fmt.Print("\n")
            fmt.Printf("------------------------\n")
        }
    }

    for _, value := range array {
        fmt.Printf("- %d\n", value)
    }

}
