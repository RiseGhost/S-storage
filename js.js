const fs = require('fs')
const path = "/tmp/sophie_storage_write"
fs.writeFileSync(path,"Cona :)")
const data = fs.readFileSync("/tmp/sophie_storage_reader",'ascii')
console.log(data.toString())