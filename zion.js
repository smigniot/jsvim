function debug(message) {
    debug_(""+message+"\n");
}
function debug_(message) {
    var zone = document.querySelector("#debug");
    zone.write(message);
    zone.scrollTop = zone.scrollHeight;
}
addEventListener("load",function() {
    debug("Initializing");
    addEventListener("keypress", function(event) {
        if(178  == event.charCode) {
            var p = document.querySelector("#terminal-popup");
            if(p.style.display == 'none') {
                p.style.display = '';
                p.querySelector("zion-terminal").focus();
            } else {
                p.style.display = 'none';
            }
        }
    });
    debug("Ready");
});

