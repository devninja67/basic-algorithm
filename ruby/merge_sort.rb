# Author: devninja67
# Time Complex: O(n*log2(n))

# separating array into 2 part( left and right) and merging sorted 2 parts
def merge_sort(arr)
  len = arr.size
  return arr if len == 1
  md = (len - 1) / 2
  left = merge_sort(arr[0..md])
  right = merge_sort(arr[(md + 1)..(len - 1)])
  merge_sort(arr[0..md])
  merge(left, right)
end

# merging sorted left and right array
def merge(left, right)
  sorted = []
  until left.empty? || right.empty?
    if left.first < right.first
      sorted << left.shift
    else
      sorted << right.shift
    end
  end
  sorted.concat(left).concat(right)
end

# Time complex and Memory test
# with random array(array that size is great than 10000) or given array by user
def random_test
  n = ARGV.size
  arr = ARGV.map {|element| element.to_f}
  if n == 0
    n = 10000 + Random.rand(10000)
    arr = n.times.map{ Random.rand(n) }
  end
  merge_sort(arr[0..n-1])
end

puts random_test