$arr = Array("a".."z")

def get_rot_n_symbol(n, symb)
	i = 0
	$arr.each do |smb|
		if smb == symb
			if i + n >= $arr.length
				return $arr[i + n - $arr.length]
			else
				return $arr[i + n]
			end
		end
		i += 1
	end
end

def rot_from_end(symb)
	i = 0
	$arr.each do |smb|
		if smb == symb
			return $arr[$arr.length - 1 - i]
		end
		i += 1
	end
end

def rot_n_text(n, text)
	new_text = " "

	i = 0
	loop do
		if $arr.include?(text[i])
			rot_symb = rot_from_end(text[i])
		else
			rot_symb = text[i]
		end

		begin
			new_text << rot_symb
		rescue Exception
			puts " -- "
		end

		i += 1
		if i == text.length
			break
		end
	end

	return new_text

end


def read_file(file_name)
	File.open(file_name, 'r') { |file| data = file.read }

end


def write_file(file_name, text)
	File.open(file_name, 'w') { |file| file.write(text) }

end

def get_symbols_freqs(text)
	freq_hash = Hash[$arr.zip(Array.new($arr.length, 0))]

	(0..text.length - 1).each do |i|
		begin
			freq_hash[text[i]] += 1
		rescue
			freq_hash[text[i]] = 0
		end
	end

	freq_hash.each_key {|k| freq_hash[k] = 1.0 * freq_hash[k] / (text.length - 1) }

	return freq_hash

end

def main
	fname = "../Sklyarov-X-Puzzle-CD/PART I/Chapter1/1.3/tatu.txt"
	# fname = "test.txt"
	text = read_file(fname)

	# freqs = get_symbols_freqs(text)
	# puts freqs
	# exit

	rotN = nil
	puts "Tested value = #{rotN}, Rotated from the end"
	puts "-" * 32
	rotted_text = rot_n_text(rotN, text)
	write_file("out.txt", rotted_text)
	puts "-" * 32

end

main