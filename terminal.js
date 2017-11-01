var ZionTerminal = Object.create(HTMLElement.prototype);
ZionTerminal.CARET = "$ ";
ZionTerminal.CARET_RE = /^\$/;
ZionTerminal.attachedCallback = function() {
    this.addEventListener("keypress",this.on_event_press.bind(this));
    this.addEventListener("keyup",this.on_event_up.bind(this));
    this.addEventListener("keydown",this.on_event_down.bind(this));
    this._io_keys = [];       
};
ZionTerminal.detachedCallback = function() {
    this.removeEventListener("keypress",this.on_event_press.bind(this));
    this.removeEventListener("keyup",this.on_event_up.bind(this));
    this.removeEventListener("keydown",this.on_event_down.bind(this));
    this._io_keys = [];       
};
ZionTerminal.reset = function() {
    window.location.reload();
};
ZionTerminal.startBufferingInput = function() {
};
ZionTerminal.SPECIALS = [8,9,13,27];
ZionTerminal.on_event_press = function(event) {
    if(this.SPECIALS.indexOf(event.keyCode) == -1) {
        this.onkey(event);
    }
};
ZionTerminal.on_event_down = function(event) {
    if(event.keyCode == 8) {
        event.preventDefault && event.preventDefault();
    }
};
ZionTerminal.on_event_up = function(event) {
    if(this.SPECIALS.indexOf(event.keyCode) != -1) {
        this.onkey(event);
    }
};
ZionTerminal.onkey = function(event) {
    event && event.preventDefault && event.preventDefault();
    var k = event.key;
    var c = event.charCode;
    var kc = event.keyCode;

    if(this._io_keys) {
        this._io_keys.push({
            "k" : event.key,
            "c" : event.charCode,
            "kc" : event.keyCode,
        });
        return;
    }
};
ZionTerminal.safeCaret = function() {
    var element = this.querySelector("zion-caret");
    if(element) {
        var before = element.previousSibling;
        var after = element.nextSibling;
        if((!before) || (before.nodeType != 3)) {
            before = document.createTextNode("");
            element.parentNode.insertBefore(before, element);
        }
        if((!after) || (after.nodeType != 3)) {
            after = document.createTextNode("");
            element.parentNode.insertBefore(after, element.nextSibling);
        }
        return {"caret":element,"before":before,"after":after};
    }
};
ZionTerminal.write = function(text) {
    var caret = this.safeCaret();
    if(caret) {
        caret.before.appendData(text);
    } else {
        this.textContent += text;
        this.scrollTop = this.scrollHeight;
    }
};
ZionTerminal.caretLeft = function() {
    var caret = this.safeCaret();
    if(caret && caret.before) {
        var data = caret.before.data;
        var n = data.length;
        if(n) {
            var c = data.slice(-1);
            caret.before.deleteData(n-1,1);
            caret.after.insertData(0,c);
        }
    }
};
ZionTerminal.caretRight = function() {
    var caret = this.safeCaret();
    if(caret && caret.after) {
        var data = caret.after.data;
        var c = data.slice(0,1);
        caret.after.deleteData(0,1);
        caret.before.appendData(c);
    }
};
ZionTerminal.caretUp = function() {
    var caret = this.safeCaret();
    if(caret && caret.before) {
        var data = caret.before.data;
        var n = data.length
        if(n) {
            var i = data.lastIndexOf("\n");
            if(i != -1) {
                var extract = data.slice(i);
                caret.before.deleteData(i,n-i);
                caret.after.insertData(0,extract);
            }
        }
    }
};
ZionTerminal.moveTo = function(row,col) {
    var sc = this.safeCaret(),
        cursor = sc.caret;

    var lines = this.textContent.split(/\n/);
    if(lines.length <= row) {
        lines = lines.concat(Array.apply(null,{
            length:(row-lines.length+1)
        }).map(function(){return ""}));
    }
    var before = lines.slice(0,row);
    var after = lines.slice(row+1);
    var line = lines[row];
    if(line.length <= col) {
        line += Array.apply(null,{length:(col-line.length+1)
            }).map(function(){return " "}).join("");
    }
    before.push(line.slice(0,col));
    after.splice(0,0,line.slice(col));

    while(this.firstChild) { this.removeChild(this.firstChild) }
    //console.log("TMP", before, after);
    this.appendChild(document.createTextNode(before.join("\n")));
    this.appendChild(cursor);
    this.appendChild(document.createTextNode(after.join("\n")));
}
ZionTerminal.caretDown = function() {
    var caret = this.safeCaret();
    if(caret && caret.after) {
        var data = caret.after.data;
        var i = data.indexOf("\n");
        if(i != -1) {
            var extract = data.slice(0,i+1);
            caret.after.deleteData(0,i+1);
            caret.before.appendData(extract);
        }
    }
};
var ZionTerminalElement = document.registerElement('zion-terminal', {
    'prototype': ZionTerminal,
});

var ZionCaret = Object.create(HTMLElement.prototype);
var ZionCaretElement = document.registerElement('zion-caret', {
    'prototype': ZionCaret,
});

