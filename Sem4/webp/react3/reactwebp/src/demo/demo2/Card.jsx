import ProfilePic from './assets/mee2.png'
function Card(){
    return(
        <div className="card">
            <img className='card-image' src={ProfilePic} alt="profile picture" />
            <h2 className='card-title'>Apoorva</h2>
            <p className='card-text'>I love playing games</p>
        </div>
    );
}
export default Card