days = {}

def parse_pair(str):
	dot_pos = str.find('.')
	if -1 == dot_pos:
		return (int(str), -1)
	return (int(str[0:dot_pos]), int(str[dot_pos+1:]))

T = int(input())

for _ in range(T):
	line = input()
	args = line.split()
	type = args[0]
	if 'S' == type:
		day = int(args[1])
		product_id, category_id = parse_pair(args[2])
		state_id, region_id = parse_pair(args[3])
		if day in days:
			if product_id in days[day]:
				if category_id in days[day][product_id]:
					if state_id in days[day][product_id][category_id]:
						if region_id in days[day][product_id][category_id][state_id]:
							days[day][product_id][category_id][state_id][region_id] += 1
						else:
							days[day][product_id][category_id][state_id][region_id] = 1
					else:
						days[day][product_id][category_id][state_id] = {}
						days[day][product_id][category_id][state_id][region_id] = 1
				else:
					days[day][product_id][category_id] = {}
					days[day][product_id][category_id][state_id] = {}
					days[day][product_id][category_id][state_id][region_id] = 1
			else:
				days[day][product_id] = {}
				days[day][product_id][category_id] = {}
				days[day][product_id][category_id][state_id] = {}
				days[day][product_id][category_id][state_id][region_id] = 1
		else:
			days[day] = {}
			days[day][product_id] = {}
			days[day][product_id][category_id] = {}
			days[day][product_id][category_id][state_id] = {}
			days[day][product_id][category_id][state_id][region_id] = 1
	else:
		d_start, d_end = parse_pair(args[1])
		if -1 == d_end:
			d_end = d_start
		product_id, category_id = parse_pair(args[2])
		state_id, region_id = parse_pair(args[3])
		count = 0
		for day in range(d_start, d_end+1):
			if day not in days:
				continue
			
			if -1 == product_id:
				# all products
				for p_id in days[day].keys():
					for c_id in days[day][p_id].keys():
						if -1 == state_id:
							# all states
							for s_id in days[day][p_id][c_id].keys():
								for r_id in days[day][p_id][c_id][s_id].keys():
									count += days[day][p_id][c_id][s_id][r_id]
						else:
							if state_id not in days[day][p_id][c_id]:
								continue
							if -1 == region_id:
								for r_id in days[day][p_id][c_id][state_id]:
									count += days[day][p_id][c_id][state_id][r_id]
							else:
								if region_id in days[day][p_id][c_id][state_id]:
									count += days[day][p_id][c_id][state_id][region_id]

			else:
				if product_id not in days[day]:
					continue
				if -1 == category_id:
					for c_id in days[day][product_id].keys():
						if -1 == state_id:
							for s_id in days[day][product_id][c_id].keys():
								for r_id in days[day][product_id][c_id][s_id].keys():
									count += days[day][product_id][c_id][s_id][r_id]
						else:
							if state_id not in days[day][product_id][c_id]:
								continue 
							if -1 == region_id:
								for r_id in days[day][product_id][c_id][state_id].keys():
									count += days[day][product_id][c_id][state_id][r_id]
							else:
								if region_id not in days[day][product_id][c_id][state_id]:
									continue
								count += days[day][product_id][c_id][state_id][region_id]								
				else:
					if category_id not in days[day][product_id]:
						continue
					if -1 == state_id:
						for s_id in days[day][product_id][category_id].keys():
							for r_id in days[day][product_id][category_id][s_id].keys():
								count += days[day][product_id][category_id][s_id][r_id]
					else:
						if state_id not in days[day][product_id][category_id]:
							continue
						if -1 == region_id:
							for r_id in days[day][product_id][category_id][state_id].keys():
								count += days[day][product_id][category_id][state_id][r_id]
						else:
							if region_id not in days[day][product_id][category_id][state_id]:
								continue
							count += days[day][product_id][category_id][state_id][region_id]

		print(count)
