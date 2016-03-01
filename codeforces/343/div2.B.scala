import io.StdIn._
import java.lang.Math._
object div2_B {
    def main(args: Array[String]){
        val n = readInt()
        var F = Vector[(String,(Int,Int))]()
        for (i <- 0 until n) {
            val ln = readLine().split(" ")
            val v = (ln(0).toString,(ln(1).toInt, ln(2).toInt))

            F = F :+ v
        }
        var res = 0
        for(i <- 1 to 366) {
            var m = 0
            var f = 0
            for(j <- 0 until F.length){
                if (F(j)._2._1 <= i && F(j)._2._2 >= i) {
                    if (F(j)._1 == "M") {
                        m = m + 1
                    }
                    else {
                        f = f + 1
                    }
                }
            }
            res = max(res, min(m,f))
        }
        println(res*2)
    }
}
