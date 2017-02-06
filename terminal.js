var ZionTerminal = Object.create(HTMLElement.prototype);
ZionTerminal.CARET = "$ ";
ZionTerminal.CARET_RE = /^\$/;
ZionTerminal.attachedCallback = function() {
    this.addEventListener("keypress",this.on_event_press.bind(this));
    this.addEventListener("keyup",this.on_event_up.bind(this));
    this.addEventListener("keydown",this.on_event_down.bind(this));
};
ZionTerminal.detachedCallback = function() {
    this.removeEventListener("keypress",this.on_event_press.bind(this));
    this.removeEventListener("keyup",this.on_event_up.bind(this));
    this.removeEventListener("keydown",this.on_event_down.bind(this));
};
ZionTerminal.eval = function(line) {
    switch(line) {
        case "help":
        case "help;":
        case "?":
            return "Try\n\t[1,2,3,4]\n\t2*Math.PI\n\tnew Date()\n\tvi\n\tclear"
            break;
        case "clear":
        case "clear;":
            var caret = this.querySelector("zion-caret");
            if(caret) {
                var text = caret.previousSibling;
                if(text.nodeType == Node.TEXT_NODE) {
                    text.textContent = this.CARET;
                    return "__NOREDRAW";
                }
            }
            break;
        case "vi":
        case "vi;":
            document.location = "./vi.html"
            return "__NOREDRAW";
    }
    return eval(line);
};
ZionTerminal.reset = function() {
    window.location.reload();
};
ZionTerminal.startBufferingInput = function() {
    this._io_keys = [];       
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

    // NEW JSVIM - transpiled xvi-249
    if(this._io_keys) {
        this._io_keys.push({
            "k" : event.key,
            "c" : event.charCode,
            "kc" : event.keyCode,
        });
        return;
    }

    // OLD JSVIM - textarea-like mode
    var caret = this.querySelector("zion-caret");
    if(caret) {
        var text = caret.previousSibling;
        if((!text) || (text.nodeType != Node.TEXT_NODE)) {
            text = document.createTextNode();
            caret.parentNode.insertBefore(text, caret);
        }
        if(("F1" == k) || (178 == c)) {
            event.preventDefault && event.preventDefault();
        } else if(("F5" == k) || (116 == kc)) {
            event.preventDefault && event.preventDefault();
            this.reset();
        } else if(("Backspace" == k) || (8 == kc) || (127 == kc)) {
            event.preventDefault && event.preventDefault();
            text.textContent = text.textContent.substring(0, 
                text.textContent.length-1);
        } else if(("ArrowLeft" == k) || (37 == kc)) {
            event.preventDefault && event.preventDefault();
            this.caretLeft();
        } else if(("ArrowUp" == k) || (38 == kc)) {
            event.preventDefault && event.preventDefault();
            this.caretUp();
        } else if(("ArrowRight" == k) || (39 == kc)) {
            event.preventDefault && event.preventDefault();
            this.caretRight();
        } else if(("ArrowDown" == k) || (40 == kc)) {
            event.preventDefault && event.preventDefault();
            this.caretDown();
        } else if(("Enter" == k) || (13 == kc)) {
            var lastline = text.textContent.substring(
                text.textContent.lastIndexOf("\n")+1).trim();
            if(lastline.match(this.CARET_RE)) {
                lastline = lastline.substring(1).trim();
            }
            try {
                var result = this.eval(lastline);
                if("__NOREDRAW" != result) {
                    var repr = (typeof "" == typeof result)?result:JSON.stringify(result);
                    text.textContent += "\n"+repr;
                    text.textContent += "\n"+this.CARET;
                }
            } catch(err) {
                text.textContent += "\n"+err;
                text.textContent += "\n"+this.CARET;
            }
        } else if(k) {
            text.textContent += k;
        } else if(c) {
            text.textContent += String.fromCharCode(c);
        }
        // this.scrollTop = caret.offsetTop; ?
        //caret.scrollIntoView();
        //this.scrollTop = this.scrollHeight;
    }
    return true;
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

