function vim_tgetnum(id) {
    if("co" == id) {
        var term = document.querySelector("zion-terminal"),
            caret = term && term.querySelector("zion-caret"),
            dim = function(e) { return getComputedStyle(e).width.replace(/px$/,"") }
            ;
        return term && Math.floor(dim(term)/dim(caret)) || 80;
    }
    if("li" == id) {
        var term = document.querySelector("zion-terminal"),
            caret = term && term.querySelector("zion-caret"),
            dim = function(e) { return getComputedStyle(e).height.replace(/px$/,"") }
            ;
        return term && Math.floor(dim(term)/dim(caret)) || 25;
    }
    return 0;
}

/**
 * The str must be a terminfo string variable or the return
 * value from tparm, tgetstr, or tgoto. affcnt is the number of lines 
 * affected, or 1 if not applicable.
 */
function vim_tputs(str, affcnt) {
    var term = document.body.querySelector("zion-terminal"),
        caret = term && term.querySelector("zion-caret")
        ;

    var m = null;
    if(m = /^\033\[<(\d+)>;<(\d+)>f$/.exec(str)) {
        var row = +(m[1]),
            col = +(m[2])
            ;
        console.log("Move cursor", row, col);
        /*
        "\b"
        "\033[1A"
        "\033[1B"
        "\r"
        "\033[1C"
        "\033[K"
        "\033[2J"
        "\033[1L"
        "\033[1M"
        "\033[H"
        */
    } else if(m = /^\033\[2J$/.exec(str)) {
        // FIXME: use scroll region
        term && [].slice.call(term.querySelectorAll("*")).forEach(function(n) {
            n && n.parentNode && (n != caret) && n.parentNode.removeChild(n);
        });
    } else {
        console.log("UNHANDLED TPUTS", str, affcnt);
        alert("WEIRD TPUTS");
        var text = document.createTextNode(str);
        if(caret)  { term.insertBefore(text, caret);  }
        else       { term.appendChild(text);          }
    }
}

function vim_kbgetc() {
    // FIXME: returns EOF in dev mode, replace by
    // jsvim's zion-terminal key buffer consumption
    var term = document.body.querySelector("zion-terminal"),
        caret = term && term.querySelector("zion-caret")
        ;
    if(term && term._io_keys && term._io_keys.length) {
        var evt = term._io_keys.splice(0,1)[0];
        return evt.kc || evt.c || evt.k.charCodeAt(0);
    }
    return 0;
}
