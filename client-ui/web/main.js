eel.expose(forward_js)
function forward_js() {
    console.log('forward_js')
    eel.forward_py()
}

eel.expose(backward_js)
function backward_js() {
    console.log('backward_js')
    eel.backward_py()
}

eel.expose(left_js)
function left_js() {
    console.log('left_js')
    eel.left_py()
}

eel.expose(right_js)
function right_js() {
    console.log('right_js')
    eel.right_py()
}

eel.expose(stop_js)
function stop_js() {
    console.log('stop_js')
    eel.stop_py()
}