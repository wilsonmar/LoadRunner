// check for IE3
var isIE3 = (navigator.appVersion.indexOf('MSIE 3') != -1);


/***************************************************************
** define and instantiate validation objects
** the validation object accepts the following parameters:
**
**   realName: name used in the alerts (same as label on the page)
**
**   formEltName: this must be the name of the corresponding
**       HTML form element; make it the same as the object name
**
**   eltType: element type (we have to create this since IE3
**       doesn't support the type property for for elements)
**     text
**     textarea
**     checkbox
**     radio
**     select
**
**   uptoSnuff: function call that's evaluated during validation check
**     isText(str)
**     isSelect(formObj)
**     isRadio(formObj)
**     isCheck(formObj, form, [index of first checkbox in group],
**         [number of checkboxes])
**     isEmail(str)
**     isState(str)
**     isZipCode(str)
**     isPhoneNum(str)
**     isDate(str)
**
**   format: text representation of required format;
**       pass 'null' if no required format;
**       used in alert as an aid to user
***************************************************************/

// object definition
function validation(realName, formEltName, eltType, upToSnuff, format) {
  this.realName = realName;
  this.formEltName = formEltName;
  this.eltType = eltType;
  this.upToSnuff = upToSnuff;
  this.format = format;
}

/***************************************************************
** create a new object for each form element you need to validate
** for example:
** var lastName = new validation('last name', 'lastName', 'text', 'isText(str)', null);
** var phoneNum = new validation('phone number', 'phoneNum', 'text', 'isPhoneNum(str)', 'xxx-xxx-xxxx');
** var reason = new validation('reason for reading this', 'reason', 'checkbox', 'isCheck(formObj, form, 14, 3)', null);
***************************************************************/
// create objects here:


var username = new validation('a username', 'username', 'text', 'isText(str)', null);
var password = new validation('a password', 'password', 'text', 'isText(str)', null);
var passwordC = new validation('a password confirmation', 'passwordConfirm', 'text', 'isText(str)', null);
var firstN = new validation('your first name', 'firstName', 'text', 'isText(str)', null);
var lastN = new validation('your last name', 'lastName', 'text', 'isText(str)', null);
var address = new validation('your address', 'address1', 'text', 'isText(str)', null);
var csz = new validation('your City/State/Zip', 'address2', 'text', 'isText(str)', null);




/***************************************************************
** Define the elts array:
** Add a new item to the array for each object you create above
** Make sure the value of the array element is the same as
** the name of the object, and that the array elements are listed
** in the same order the corresponding objects appear in the form
** (it's more clear to the user that way)
** for example:
** var elts = new Array(lastName, phoneNum, reason)
***************************************************************/
var elts = new Array(username, password, passwordC, firstN, lastN, address, csz);



/***************************************************************
** The main function keeps track of which fields the user missed
** or filled in incorrectly, and alerts the user so they can go
** back and fix what's wrong.
** Set allAtOnce to true if you want this "validation help" to
** alert the user to all mistakes at once; set it to false if
** you want it to show one mistake at a time
***************************************************************/
var allAtOnce = true;


/***************************************************************
** change text for alerts here
** unspecified field (text): "Please include [field name]."
** unspecified field (other): "Please choose [field name]."
** invalid text field entries: "[field value] is an invalid [field name]!"
** help with format: "Use this format: "
***************************************************************/
var beginRequestAlertForText = "Please include ";
var beginRequestAlertGeneric = "Please choose ";
var endRequestAlert = ".";
var beginInvalidAlert = " is an invalid ";
var endInvalidAlert = "!";
var beginFormatAlert = "  Use this format: ";


/***************************************************************
** these functions validate the string or form object passed in,
** and return true or false based on whether the test succeeds or fails
**
** validate existence of input
**   isText(str): verifies text input or textarea is not empty
**   isSelect(formObj): verifies item from a select menu is chosen
**   isRadio(formObj): verifies one of a group of radio buttons is chosen
**   isCheck(formObj, form, [begin], [num]): verifies at least one
**       of a group of checkboxes is checked
**     for [begin], fill in the index number in the elements array
**         of the first checkbox (remember to start counting from zero)
**     for [num], fill in the number of checkboxes in the group
**
** validate text in text input or textarea matches pattern
**   isEmail(str): verifies email address (contains "@" and ".")
**   isState(str): verifies U.S. State Code
**   isZipCode(str): verifies zip code of form xxxxx or xxxxx-xxxx
**   isPhoneNum(str): verifies phone number of form xxx-xxx-xxxx
**   isDate(str): verifies date of form mm/dd/yyyy
***************************************************************/

function isText(str) {
  return (str != "");
}

function isSelect(formObj) {
  return (formObj.selectedIndex != 0);
}

function isRadio(formObj) {
  for (j=0; j<formObj.length; j++) {
    if (formObj[j].checked) {
      return true;
    }
  }
  return false;
}

function isCheck(formObj, form, begin, num) {
  for (j=begin; j<begin+num; j++) {
    if (form.elements[j].checked) {
      return true;
    }
  }
  return false;
}

function isEmail(str) {
  return ((str != "") && (str.indexOf("@") != -1) && (str.indexOf(".") != -1));
}

function isState(str) {
  str = str.toUpperCase();
  return ( (str == "AK") || (str == "AL") || (str == "AR") || (str == "AZ") || (str == "CA") || (str == "CO") || (str == "CT") || (str == "DC") || (str == "DE") || (str == "FL") || (str == "GA") || (str == "HI") || (str == "IA") || (str == "ID") || (str == "IL") || (str == "IN") || (str == "KS") || (str == "KY") || (str == "LA") || (str == "MA") || (str == "MD") || (str == "ME") || (str == "MI") || (str == "MN") || (str == "MO") || (str == "MS") || (str == "MT") || (str == "NB") || (str == "NC") || (str == "ND") || (str == "NH") || (str == "NJ") || (str == "NM") || (str == "NV") || (str == "NY") || (str == "OH") || (str == "OK") || (str == "OR") || (str == "PA") || (str == "RI") || (str == "SC") || (str == "SD") || (str == "TN") || (str == "TX") || (str == "UT") || (str == "VA") || (str == "VT") || (str == "WA") || (str == "WI") || (str == "WV") || (str == "WY") );
}

function isZipCode(str) {
  var l = str.length;
  if ((l != 5) && (l != 10)) { return false }
  for (j=0; j<l; j++) {
    if ((l == 10) && (j == 5)) {
      if (str.charAt(j) != "-") { return false }
    } else {
      if ((str.charAt(j) < "0") || (str.charAt(j) > "9")) { return false }
    }
  }
  return true;
}

function isPhoneNum(str) {
  if (str.length != 12) { return false }
  for (j=0; j<str.length; j++) {
    if ((j == 3) || (j == 7)) {
      if (str.charAt(j) != "-") { return false }
    } else {
      if ((str.charAt(j) < "0") || (str.charAt(j) > "9")) { return false }
    }
  }
  return true;
}

function isDate(str) {
  if (str.length != 10) { return false }

  for (j=0; j<str.length; j++) {
    if ((j == 2) || (j == 5)) {
      if (str.charAt(j) != "/") { return false }
    } else {
      if ((str.charAt(j) < "0") || (str.charAt(j) > "9")) { return false }
    }
  }

  var month = str.charAt(0) == "0" ? parseInt(str.substring(1,2)) : parseInt(str.substring(0,2));
  var day = str.charAt(3) == "0" ? parseInt(str.substring(4,5)) : parseInt(str.substring(3,5));
  var begin = str.charAt(6) == "0" ? (str.charAt(7) == "0" ? (str.charAt(8) == "0" ? 9 : 8) : 7) : 6;
  var year = parseInt(str.substring(begin, 10));

  if (day == 0) { return false }
  if (month == 0 || month > 12) { return false }
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
    if (day > 31) { return false }
  } else {
    if (month == 4 || month == 6 || month == 9 || month == 11) {
      if (day > 30) { return false }
    } else {
      if (year%4 != 0) {
        if (day > 28) { return false }
      } else {
        if (day > 29) { return false }
      }
    }
  }
  return true;
}


/***************************************************************
** The validateForm() function validates the form elements
** previously defined as validation objects and as members of
** the elts array. We loop through the elts array, testing each
** element in turn, and alerting the user when they've missed
** a required field
***************************************************************/

function validateForm(form) {
  var formEltName = "";
  var formObj = "";
  var str = "";
  var realName = "";
  var alertText = "";
  var firstMissingElt = null;
  var hardReturn = "\r\n";

  for (i=0; i<elts.length; i++) {
    formEltName = elts[i].formEltName;
    formObj = eval("form." + formEltName);
    realName = elts[i].realName;

    if (elts[i].eltType == "text") {
      str = formObj.value;

      if (eval(elts[i].upToSnuff)) continue;

      if (str == "") {
        if (allAtOnce) {
          alertText += beginRequestAlertForText + realName + endRequestAlert + hardReturn;
          if (firstMissingElt == null) {firstMissingElt = formObj};
        } else {
          alertText = beginRequestAlertForText + realName + endRequestAlert + hardReturn;
          alert(alertText);
        }
      } else {
        if (allAtOnce) {
          alertText += str + beginInvalidAlert + realName + endInvalidAlert + hardReturn;
        } else {
          alertText = str + beginInvalidAlert + realName + endInvalidAlert + hardReturn;
        }
        if (elts[i].format != null) {
          alertText += beginFormatAlert + elts[i].format + hardReturn;
        }
        if (allAtOnce) {
          if (firstMissingElt == null) {firstMissingElt = formObj};
        } else {
          alert(alertText);
        }
      }
    } else {
      if (eval(elts[i].upToSnuff)) continue;
      if (allAtOnce) {
        alertText += beginRequestAlertGeneric + realName + endRequestAlert + hardReturn;
        if (firstMissingElt == null) {firstMissingElt = formObj};
      } else {
        alertText = beginRequestAlertGeneric + realName + endRequestAlert + hardReturn;
        alert(alertText);
      }
    }
    if (!isIE3) {
      var goToObj = (allAtOnce) ? firstMissingElt : formObj;
      if (goToObj.select) goToObj.select();
      if (goToObj.focus) goToObj.focus();
    }
    if (!allAtOnce) {return false};
  }
  if (allAtOnce) {
    if (alertText != "") {
      alert(alertText);
      return false;
    }
  } 
//  alert("I am valid!"); //remove this line when you use the code
  return true; //change this to return true to make the form submit
}
