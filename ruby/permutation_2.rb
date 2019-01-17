# Author   : devninja67
# inputs   : N = 3
# outputs  : 123
#            213
#            231
#            132
#            312
#            321

N = ARGV[0].to_i == 0? 3 : ARGV[0].to_i
flg = Array.new(N)

puts permutation 1