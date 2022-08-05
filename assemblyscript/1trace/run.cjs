// Assume add.wasm file exists that contains a single function adding 2 provided arguments
const fs = require('fs');

const wasmBuffer = fs.readFileSync('build/debug.wasm');
const memory = new WebAssembly.Memory({ initial: 10 });
function getString(ptr) {
  const RUNTIME_HEADER_SIZE = 16;
  if (!ptr) return "null";
  var U32 = new Uint32Array(exports.memory ? exports.memory.buffer : memory.buffer);
  var U16 = new Uint16Array(exports.memory ? exports.memory.buffer : memory.buffer);
  var len16 = U32[(ptr - RUNTIME_HEADER_SIZE + 12) >>> 2] >>> 1;
  var ptr16 = ptr >>> 1;
  return String.fromCharCode.apply(String, U16.subarray(ptr16, ptr16 + len16));
}

const imports = {
  env: {
    abort(_msg, _file, line, column) {
       console.error("abort called at index.ts:" + line + ":" + column);
    },
    // memory: new WebAssembly.Memory({initial:1})
    trace: function(msg, n) {
      console.log("  trace: " + getString(msg) + (n ? " " : "") + Array.prototype.slice.call(arguments, 2, 2 + n).join(", "));
    }
  }
};
WebAssembly.instantiate(wasmBuffer, imports).then(wasmModule => {
  // Exported function live under instance.exports
  const { add } = wasmModule.instance.exports;
  
  let a = add(4); // int is 4 bytes
  console.log(a);
  // let b = extractHeader();
  // console.log(b);
  // let c = wasmModule.instance.__getString(extractHeader());
  // console.log(c);

});
