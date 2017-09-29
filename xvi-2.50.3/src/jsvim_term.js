function vim_tgetnum(isCO, isLI) {
    console.log("TGETNUM", isCO, isLI);
    return isCO?80:(isLI?25:0);
}
