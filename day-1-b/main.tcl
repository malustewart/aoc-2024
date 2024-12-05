while {[gets stdin line] >= 0} {
  lappend left [lindex [join $line " "] 0]
  lappend right [lindex [join $line " "] 1]
}
# 1A
#set sum 0
#foreach l [lsort $left] r [lsort $right] {set sum [expr {$sum+abs($l-$r)}]}
#puts $sum

proc lcount {listt nemo} {
  set count 0
  foreach item $listt {
    if {$item == $nemo} {
      incr count
    }
  }
  return $count
}
set sum 0
foreach item [lsort -unique $left] { 
  incr sum [expr {$item * [lcount $left $item ] * [lcount $right $item]} ] 
}
puts $sum