function debug(message) {
    var zone = document.querySelector("#debug");
    zone.write(""+message+"\n");
    zone.scrollTop = zone.scrollHeight;
}
addEventListener("load",function() {
    document.body.addEventListener("dragover", function(event) {
        var dropzone = document.querySelector("zion-drop");
        if(dropzone) {
            event.preventDefault();
            event.dataTransfer.dropEffect = "copy";
        }
    });
    document.body.addEventListener("drop", function(event) {
        var dropzone = document.querySelector("zion-drop");
        if(dropzone) {
            event.preventDefault();
            var files = event.dataTransfer.files;
            if(files) dropzone.dropped(files);
        }
    });
});

var ZionDrop = Object.create(HTMLElement.prototype);
ZionDrop.dropped = function(files) {
    if(!files) return;
    [].forEach.call(files, function(file) {
        var reader = new FileReader();
        reader.onload = function(event) {
            this.incoming(file.name, event.target.result);
        }.bind(this);
        reader.readAsDataURL(file);
    }.bind(this));
};
ZionDrop.incoming = function(filename, content) {
    var file = document.createElement("zion-file");
    file.filename = filename;
    file.href = "url("+content+")";
    document.body.appendChild(file);
    debug("Dropped "+filename);
};
var ZionDropElement = document.registerElement('zion-drop', {
    'prototype': ZionDrop,
});

var ZionFile = Object.create(HTMLElement.prototype, {
    'filename': {
        'get': function() { return this.getAttribute("filename"); },
        'set': function(filename) { return this.setAttribute("filename", filename); }
    },
    'href': {
        'get': function() { 
            var a = this.querySelector("a");
            if(a) {
                return a.getAttribute("href");
            }
        },
        'set': function(href) { 
            var a = this.querySelector("a");
            if(!a) {
                a = document.createElement("a");
                this.appendChild(a);
            }
            a.setAttribute("href", href);
        }
    }
});
var ZionFileElement = document.registerElement('zion-file', {
    'prototype': ZionFile,
});
