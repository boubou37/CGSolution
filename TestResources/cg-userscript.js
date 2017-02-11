// ==UserScript==
// @name     Codingame Download Test cases
// @match    *://www.codingame.com/*
// @version  1.0
// @require http://code.jquery.com/jquery-3.1.1.js
// ==/UserScript==
(function() {

    var saveData = (function () {
        var a = document.createElement("a");
        document.body.appendChild(a);
        a.style = "display: none";
        return function (data, fileName) {
            var blob = new Blob([data], {type: "text/plain"}),
                url = window.URL.createObjectURL(blob);
            a.href = url;
            a.download = fileName;
            a.click();
            window.URL.revokeObjectURL(url);
        };
    }());


    var doStuff = function () {
        document.querySelector("div.header-buttons button[translate-attr-title='cgIde.showTestcases']").click();
        var tests;
        do {
            tests = document.querySelectorAll(".testcase-header");
        } while (tests === undefined);
        for (var i=0; i<tests.length; i++) {
            tests[i].click();
            var test;
            do {
                test = document.querySelector("pre.testcase-in");
            } while (test === undefined);
            var txt = test.innerHTML;
            fileName = "Test"+i+".txt";
            saveData(txt, fileName);
        }
        /* var txt = document.querySelector("pre.testcase-in").innerHTML;
         fileName = "my-download.json";
saveData(txt, fileName);*/
    };

    var observer = new MutationObserver(function(mutations) {
        mutations.forEach(function(mutation) {
            for (let i = 0; i < mutation.addedNodes.length; i++) {
                if (mutation.addedNodes[i].nodeType !== 1) { // ELEMENT_NODE
                    continue;
                }

                let test = mutation.addedNodes[i].querySelector("div.header-buttons button[translate-attr-title='cgIde.showTestcases']");
                let buttons = mutation.addedNodes[i].querySelector("div.code-buttons");
                if (!test || !buttons) {
                    continue;
                }

                var button = document.createElement("input");
                button.type = "button";
                button.className = "ide-tab";
                button.value = "Download test";
                button.addEventListener('click', doStuff, false);

                buttons.insertBefore(button, buttons.firstChild);
            }

        });
    });

    observer.observe(document.body, {
        subtree: true,
        childList: true,
        attributes: false,
        characterData: false
    });


})();
