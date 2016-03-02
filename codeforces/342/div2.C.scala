import scala.io.Source

object round_342_div2_C {
    def main(args: Array[String]){
        val in = Source.stdin.getLines()
        val ln = in.next().split(" ")
        val n = ln(0).toInt
        val k = ln(1).toInt

        var tot = 0
        for (i <- 1 to n) {
            tot += 1+n*(k-1) + (i-1)*(n-k+1)
        }
        println(tot)


        for (i <- 1 to n) {
            //for (j <- 1 to (k - 1)) {
            //    res = res + "%d ".format(j+(i-1)*(k-1))
            //}
            val left = 1+(i-1)*(k-1) to (k-1)+(i-1)*(k-1)
            //for (j <- 1 to (n - k + 1)) {
            //   res = res + "%d ".format(j + n*(k-1) + (i-1)*(n-k+1))
            //}
            val right = 1+n*(k-1)+(i-1)*(n-k+1) to (n-k+1) + n*(k-1)+(i-1)*(n-k+1)
            
            println((left++right).mkString(" ").trim)
        }
    }
}
