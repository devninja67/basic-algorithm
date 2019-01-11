# calculate check sum using luhn algorithm.
# Author : devninja67

def sumLuhn(barcode, nParity)
  checksum = 0
  for i in 0..barcode.length - 1
    nDigit = barcode[i].to_i
    if nParity == (i & 1) # i % 2
      nDigit = (nDigit << 1) # nDigit * 2
    end
    checksum = checksum + nDigit / 10 + nDigit % 10
  end
  return checksum % 10
end

#return turn if current barcode( including checkdigit ) validates, false if not.

def checkLuhn1(barcode)
  nParity = (barcode.length & 1) # barcode.length % 2 
  return sumLuhn(barcode, nParity) == 0
end

#return string if current barcode joined checkdigit as suffix.

def checkLuhn2(barcode)
  nParity = (1 ^ (barcode.length & 1)) # 1 - (barcode.length % 2)
  checksum = sumLuhn(barcode, nParity)
  return barcode + "#{(10 - checksum % 10) % 10}"
end

puts checkLuhn1("79927398713") # return ture if valid barcode, return false if invalid barcode
puts checkLuhn2("7992739871") # return checkcode