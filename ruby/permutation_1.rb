# Author   : devninja67
# inputs   : N = 3
# outputs  : 123
#            213
#            231
#            132
#            312
#            321

N = ARGV[0].to_i

def permutation(n)
  return [""] if n > N
  permutation(n + 1).each_with_object([]) do |perm, result|
    (0..perm.size).each { |i| result << perm.dup.insert(i, n.to_s)}
  end
end

puts permutation 1