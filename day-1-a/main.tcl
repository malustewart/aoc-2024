while {[gets stdin line] >= 0} {
  lappend left [lindex [join $line " "] 0]
  lappend right [lindex [join $line " "] 1]
}
set sum 0
foreach l [lsort $left] r [lsort $right] {set sum [expr {$sum+abs($l-$r)}]}
puts $sum