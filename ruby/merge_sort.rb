def merge_sort(arr)
  len = arr.size
  return arr if len == 1
  md = (len - 1) / 2
  left = merge_sort(arr[0..md])
  right = merge_sort(arr[(md + 1)..(len - 1)])
  merge_sort(arr[0..md])
  merge(left, right)
end

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

def random_test
  n = ARGV.size
  arr = ARGV.map {|element| element.to_f}
  if n == 0
    n = 100000 + Random.rand(100000)
    arr = n.times.map{ Random.rand(n) }
  end
  merge_sort(arr[0..n-1])
end

puts random_test