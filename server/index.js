var express = require('express')
var app = express()

var ok = 0, bad = 0;


var fs = require('fs') // this engine requires the fs module
app.engine('html', function (filePath, options, callback) { // define the template engine
  fs.readFile(filePath, function (err, content) {
    if (err) return callback(err)
    // this is an extremely simple template engine
    var rendered = content.toString().replace('#ok#', options.ok).replace('#bad#', options.bad)
    return callback(null, rendered)
  })
})
app.set('views', './html') // specify the views directory
app.set('view engine', 'html') // register the template engine


app.get('/ok', function (req, res) {
	console.log("ok")
	ok++
   res.send('ok')
})

app.get('/bad', function (req, res) {
	bad++
	res.send('ok')
})

app.get('/', function (req, res) {
	console.log("HP")
  res.render('views', { ok, bad })
})


app.listen(3000, function () {
  console.log('Example app listening on port 3000!')
})