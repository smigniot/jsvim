function startJsvim(container) {
    var term = new Terminal({
        cols:80, rows:24,
        fontSize: 12,
        tabStopWidth: 4,
        cursorBlink: true,
        convertEol: false,
    });
    term.open(container);
    return term;
}
function jsvimOnLoad() {
    var $ = s=>document.querySelector(s);
    var container = $('#terminal-container');
    var term = startJsvim(container);
    container.term = term
}
function execPre(pre) {
    var $ = s=>document.querySelector(s);
    var container = $('#terminal-container');
    container.term.write(xxd2str(pre.textContent));
}
function xxd2str(xxd) {
    return xxd
        .split(/[\r\n]+/)
        .filter(l=>l.match(/^\d{8}: /))
        .map(l=>l.slice(10,50).replace(/\s+/g,""))
        .join("").match(/../g)
        .map(h=>String.fromCharCode(parseInt(h,16)))
        .join("")
        ;
}
