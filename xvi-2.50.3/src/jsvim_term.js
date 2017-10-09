function vim_tgetnum(id) {
    if("co" == id) return 80;
    if("li" == id) return 25;
    return 0;
}

function vim_tputs(str, affcnt) {
    console.log("TPUTS", str, affcnt);
}

function vim_kbgetc() {
    // FIXME: returns EOF in dev mode, replace by
    // jsvim's zion-terminal key buffer consumption
    return 0;
}
