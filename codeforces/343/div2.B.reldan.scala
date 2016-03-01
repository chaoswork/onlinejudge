import scala.io.Source

object Solution  {
def main(args: Array[String]){
  val in = Source.stdin.getLines()
  val n = in.next().toInt
  val data = (1 to n).map { _ =>
    val Array(sex, start, end) = in.next().split(' ')
    (sex.head, start.toInt, end.toInt)
  }
  println(2 * (1 to 366).foldLeft(0) {
    case(acc, i) =>
      //println("i=%d".format(i))
      val res = data.foldLeft((0, 0)) {
        case((m, f), ('M', start, end)) if i >= start && i <= end => (m + 1, f)
        case((m, f), ('F', start, end)) if i >= start && i <= end => (m, f + 1)
        case(bcc, x) => {
            //println(bcc,x)
            bcc
            }
      }
      Math.max(acc, Math.min(res._1, res._2))
  })
}
}
