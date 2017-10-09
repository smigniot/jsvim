FAQ1: If you're looking for a Vim *ported* to javascript, follow the link to [Lu Wang's amazing work](https://coolwanglu.github.io/vim.js/streamlinejs/vim.html)

FAQ2: This project is named JSVim for historical reasons and shall be named JSxvi. Big thanks to [Martin Guy](http://martinwguy.github.io/xvi/)


First to prevent [HolyWars](http://wiki.c2.com/?HolyWar) let me tell you what JSVim isn't.

* It is not the [excellent packaging of vim made by Lu Wang](https://coolwanglu.github.io/vim.js/streamlinejs/vim.html) - wish it were, smaller.
* It is not an Atom-like or [NeoVim all-in-one](/r/neovim)
* It is not an &quot;A few keys implemented&quot; vi-clone. Been there with [JSVim3.0](https://www.migniot.com/JSVim.html) - you can't sync vim selection with [Range](https://developer.mozilla.org/en-US/docs/Web/API/range) properly in a TextArea
* It is not the quite minimal code spread [since decades](http://gpl.internetconnection.net/vi/)


That said

JSVim, in its 4.0 version is an HTML5 CustomElement TextArea extension which aims at
* Providing the full  [xvi runtime](http://martinwguy.github.io/xvi/) through Emscripten - xvi-2.50.3 under merge
* Provide a TERM implementation in CustomElement compatible with HTML5 capabilities - fighting for it
* Stay Small ! - NonArguableMatter



