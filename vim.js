function vim_getColumns() {
    return 24;
}

function vim_getRows() {
    return 80;
}

function vim_eventLoop() {
    console.log("tick");
    Module.ccall("xvi_loop");
    setTimeout(vim_eventLoop, 500);
}

function vim_tputs(ptr_str) {
    var text = UTF8ToString(ptr_str);
    console.log("vim_tputs",text);
    return -1;
}

