var fm = require('./fileManipulation.js');

() => {
    var releasePath = '../bin/Release/';
    
    var dlls = fm.readJsonContents('dynamicLibs.json'); 
    
    for (dllName in dlls) {
        console.log('copying over the ' + dllName + ' to ' + releasePath);
        fm.copyFile(dlls[dllName], releasePath + dllName, () => {});
    }
}();