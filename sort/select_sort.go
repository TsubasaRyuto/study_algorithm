package main
import "fmt"
func main(){
    array := []int{ 10, 8, 52, 17, 3, 31 }
    min_num := array[0]
    min_num_index := 0

    for i := 0; i <= len(array) - 1; i++ {
        min_num = array[i]
        min_num_index = i

        for j := i; j <= len(array) - 1; j++ {
            if (min_num > array[j]) {
                min_num = array[j]
                min_num_index = j
            }
        }

        w := array[i]
        array[i] = min_num
        array[min_num_index] = w

        for _, value := range array {
            fmt.Printf(" - %d", value)
        }
        fmt.Print("\n")
        fmt.Printf("------------------------\n")
    }
}
