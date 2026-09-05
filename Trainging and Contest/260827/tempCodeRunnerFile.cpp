
    if (lazy_add[p]) {
        apply_add(p << 1, l, mid, lazy_add[p]);
        apply_add(p << 1 | 1, mid + 1, r, lazy_add[p]);
        lazy_add[p] = 0;
    }