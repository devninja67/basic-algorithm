# Author   : devninja67
# inputs   : N = 3
# outputs  : 123
#            213
#            231
#            132
#            312
#            321

N = ARGV[0].to_i == 0? 3 : ARGV[0].to_i
$flg = Array.new(N + 1)
$perm = String.new("")

def permutation(n)
  if n > N
    puts $perm
    return
  end
  for i in 1..N
    next if $flg[i]
    $flg[i] = true
    $perm << i.to_s
    permutation n + 1
    $flg[i] = false
    $perm = $perm.slice(0..-2)
  end
end

permutation 1