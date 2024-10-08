pub fn strpcmp(query: &[u8], pattern: &[u8]) -> bool {
	let mut q = 0;
	let mut p = 0;
	let q_len = query.len();
	let p_len = pattern.len();
	let mut star_p = None;
	let mut star_q = 0;

	while q < q_len {
		if p < p_len && (pattern[p] == query[q] || pattern[p] == b'*') {
			if pattern[p] == b'*' {
				star_p = Some(p);
				star_q = q;
				p += 1;
			} else {
				p += 1;
				q += 1;
			}
		} else if let Some(last_star_p) = star_p {
			p = last_star_p + 1;
			star_q += 1;
			q = star_q;
		} else {
			return false
		}
	}
	while p < p_len && pattern[p] == b'*' {
		p += 1;
	}
	p == p_len
}