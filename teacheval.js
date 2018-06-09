function te_callback(resp)
{
	if (resp.id == 'evalItemId')
		parse_list(resp);
	else
		handle_one(resp);
};

function solve()
{
	if (i >= len) return;
	$('#'+list[i]).removeClass('table-primary').addClass('table-info');
    invokeCSharpAction('post;action/eval/eval-with-answer.do;{"guidelineId":"120","evalItemId":"' + list[i] + '","answers":{"prob11":"A","prob12":"A","prob13":"N","prob14":"A","prob15":"A","prob21":"A","prob22":"A","prob23":"A","prob31":"A","prob32":"A","prob33":"A","prob41":"A","prob42":"A","prob43":"A","prob51":"A","prob52":"A","sat6":"A","mulsel71":"K","advice72":"good","prob73":"Y"},"clicks":{"mulsel71":176187,"prob11":143759,"prob12":146540,"prob13":148790,"prob14":150583,"prob15":152233,"prob21":153748,"prob22":155383,"prob23":156628,"prob31":158877,"prob32":161367,"prob33":164157,"prob41":165950,"prob42":167053,"prob43":168304,"prob51":169768,"prob52":170968,"prob73":177732,"sat6":172791,"_boot_":0}}');
};

function handle_one(resp)
{
	if (resp.count != 1)
	{
		$('#'+list[i]).removeClass('table-primary').addClass('table-warning');
		invokeCSharpAction('msg;' + resp.msg);
	}
	else
	{
		$('#'+list[i]).removeClass('table-primary').addClass('table-info');
		i++;
		solve();
	}
};

function parse_list(resp)
{
    for(var p = 0; p < resp.value.length; p++)
    {
        $('#evalItemList').append('<tr id="' + resp.value[p].evalItemId + '" class="' + (resp.value[p].evalActTime.evalGuideline.evalGuidelineId == '120' ? 'table-primary' : 'table-warning') + '"><td>' + resp.value[p].target.name + '</td><td>' + resp.value[p].target.school.schoolName + '</td>' + (uwp ? '<td>' + resp.value[p].evalActTime.evalTime.title + '</td>' : '') + '</tr>');
        if (resp.value[p].evalActTime.evalGuideline.evalGuidelineId == '120')
        {
            len = list.push(resp.value[p].evalItemId);
        }
    }
    invokeCSharpAction('finished');
}

$(function(){
  invokeCSharpAction('begin');
  invokeCSharpAction('post;service/res.do;{"tag":"student@evalItem","branch":"self","params":{"blank":"Y"}}');
});
