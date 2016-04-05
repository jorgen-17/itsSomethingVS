var fm = require('./fileManipulation.js');

() => {
    var debugPath = '../bin/Debug/';
    
    var dlls = fm.readJsonContents('dynamicLibs.json'); 
    
    for (dllName in dlls) {
        console.log('copying over the ' + dllName + ' to ' + debugPath);
        fm.copyFile(dlls[dllName], debugPath + dllName, () => {});
    }
}();